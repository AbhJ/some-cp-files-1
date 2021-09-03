import matplotlib.pyplot as plt
import random
import numpy as np
# in TSP graph is complete


class TSP_using_GA(object):
	# this function initializes the variables in the class for the application of
	# evolutionary algorithm
    def __init__(self, location_count, cross_rate, mutation_rate, pop_size):
        self.location_count = location_count
        self.cross_rate = cross_rate
        self.mutation_rate = mutation_rate
        self.pop_size = pop_size
        self.pop = np.vstack([np.random.permutation(location_count) for _ in range(pop_size)])
	# this function is called in plotting graph and helps to create lines for
	# joining location nodes
    def helper_for_plotting_graph(self, graph, city_position):
        line_x = np.empty_like(graph, dtype=np.float64)
        line_y = np.empty_like(graph, dtype=np.float64)
        for i, d in enumerate(graph):
            city_coord = city_position[d]
            line_x[i, :] = city_coord[:, 0]
            line_y[i, :] = city_coord[:, 1]
        return line_x, line_y
	# this function selects and returns random child of given fitness value
    def select(self, fitness):
        idx = np.random.choice(np.arange(self.pop_size), size=self.pop_size, replace=True, p=fitness / fitness.sum())
        return self.pop[idx]
	# this function returns fitness of a given graph in terms of metric or euclidean distance
    def get_fitness(self, line_x, line_y):
        total_distance = np.empty((line_x.shape[0],), dtype=np.float64)
        for i, (xs, ys) in enumerate(zip(line_x, line_y)):
            total_distance[i] = np.sum(np.sqrt(np.square(np.diff(xs)) + np.square(np.diff(ys))))
        fitness = np.exp(self.location_count * 2 / total_distance)
        return fitness, total_distance
	# this is the evolutionary function that keeps getting called till the desired number of generations
    def evolve(self, fitness):
        pop = self.select(fitness)
        pop_copy = pop.copy()
        for parent in pop:
            child = self.crossover(parent, pop_copy)
            child = self.mutate(child)
            parent[:] = child
        self.pop = pop
	# this function generates cross over between two individuals with given cross-over rate
    def crossover(self, parent, pop):
        if np.random.rand() < self.cross_rate:
            i_ = np.random.randint(0, self.pop_size, size=1)                        # select another individual from pop
            cross_points = np.random.randint(0, 2, self.location_count).astype(bool)      # choose crossover points
            keep_city = parent[~cross_points]                                       # find the city number
            swap_city = pop[i_, np.isin(pop[i_].ravel(), keep_city, invert=True)]
            parent[:] = np.concatenate((keep_city, swap_city))
        return parent
	# this function mutates an individual with given mutation rate
    def mutate(self, child):
        for point in range(self.location_count):
            if np.random.rand() < self.mutation_rate:
                swap_point = np.random.randint(0, self.location_count)
                swapA, swapB = child[point], child[swap_point]
                child[point], child[swap_point] = swapB, swapA
        return child

# this is the main function that runs the evolutionary algorithm
class ready_for_TSP(object):
    def __init__(self, n_cities):
        self.city_position = np.random.rand(n_cities, 2)
        plt.ion()

    def printer_function(self, lx, ly, total_d):
        plt.cla()
        plt.scatter(self.city_position[:, 0].T, self.city_position[:, 1].T, s=100, c='k',)
        plt.plot(lx.T, ly.T, 'r-',)
        plt.text(-0.05, -0.05, "Total distance=%.2f" % total_d, fontdict={'size': 20, 'color': np.random.rand(3,)})
        plt.xlim((-0.1, 1.1))
        plt.ylim((-0.1, 1.1))
        plt.pause(0.01)
location_count = int(input("Enter number of locations (0 - 20) in integer f0orm: ")) # count of locations
crossover_rate = float(input("Enter crossover rate (0 - 1) in floating point form: ")) # cross over rate
mutation_rate = float(input("Enter mutation rate (0 - 1) in floating point form: ")) # mutation rate
generation_count = int(input("Enter number of generations (0 - 100) in integer form: ")) # number of generations
ga = TSP_using_GA(location_count=location_count, cross_rate=crossover_rate, mutation_rate=mutation_rate, pop_size=500)
env = ready_for_TSP(location_count)
for generation in range(generation_count):
    lx, ly = ga.helper_for_plotting_graph(ga.pop, env.city_position)
    fitness, total_distance = ga.get_fitness(lx, ly)
    ga.evolve(fitness)
    best_idx = np.argmax(fitness)
    print('Generation index:', generation, '| fitness of fittest tour: %.2f' % fitness[best_idx])
    env.printer_function(lx[best_idx], ly[best_idx], total_distance[best_idx])


plt.ioff()
plt.show()