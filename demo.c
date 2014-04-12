#include <math.h>
#include <string.h>
#include <gsl/gsl_rng.h>
#include "pso.h"

#define _USE_MATH_DEFINES

float first_sum(double *vec, int n) {

	double sum = 0;
	int i;
	for(i = 0; i < n; i++)
		sum += pow(vec[i], 2);
	sum /= n;
	return -0.2 * sqrt(sum);
}

float second_sum(double *vec, int n) {

	double sum = 0;
	int i;
	for(i = 0; i < n; i++)
		sum += cos(2 * M_PI * vec[i]);
	sum /= n;
	return sum;
}

double pso_ackley(double *vec, int dim, void *params) {

	return -20 * exp(first_sum(vec, 8)) - exp(second_sum(vec, 8)) + 20 + M_E;
}
void pso_set_ackley_settings(pso_settings_t *settings) {

    settings->x_lo = -32.768;
    settings->x_hi = 32.768;
    settings->goal = 1e-5;

}

int main(int argc, char **argv) {

    // define objective function
    pso_obj_fun_t obj_fun = pso_ackley;
    // initialize pso settings
    pso_settings_t settings;
    // set the default settings
    pso_set_default_settings(&settings);

    // set PSO settings manually
    settings.size = 30;
    settings.nhood_strategy = PSO_NHOOD_RING;
    settings.nhood_size = 10;
    settings.w_strategy = PSO_W_LIN_DEC;

	pso_set_ackley_settings(&settings);
	printf("Optimizing function: ackley (dim=%d, swarm size=%d)\n",
			settings.dim, settings.size);

    // initialize GBEST solution
    pso_result_t solution;
    // allocate memory for the best position buffer
    solution.gbest = malloc(settings.dim * sizeof(double));

    // run optimization algorithm
    pso_solve(obj_fun, NULL, &solution, &settings);

    // free the gbest buffer
    free(solution.gbest);
    
    return 0;
}
