#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

clock_t start_time;
struct rusage usage_start;

__attribute__((constructor))
	void start_program() {
		// Record start time and memory usage
		start_time = clock();
		getrusage(RUSAGE_SELF, &usage_start);
	}

void get_memory_usage() {
	// Record end memory usage
	struct rusage usage_end;
	getrusage(RUSAGE_SELF, &usage_end);
	printf("Memory used: %ld KB\n", usage_end.ru_maxrss - usage_start.ru_maxrss);
}

__attribute__((destructor))
	void end_program() {
		clock_t end_time = clock();  // Record the end time
		double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		printf("Execution time: %.5f seconds\n", time_taken);
		get_memory_usage();
	}
