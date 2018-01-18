//
//  main.cpp
//  maze_astar
//
//  Created by Ler Wilson on 17/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <list>

#define MAX 11

using namespace std;

class coords_t {
public:
    int x, y;
    double g_cost;
    double h_cost;
    coords_t* parent;
    // Constructor
    coords_t() {
    }
    bool operator== (coords_t other) {
        if (other.x == this->x && other.y == this->y) {
            return true;
        }
        return false;
    }
    bool operator!= (coords_t other) {
        if (other.x != this->x && other.y != this->y) {
            return true;
        }
        return false;
    }
private:
};

double cartesian_count (int x, int y, int x_target, int y_target) {
    double difference_x = x - x_target;
    double difference_y = y - y_target;
    return sqrt (difference_x*difference_x + difference_y*difference_y);
}

void scan_maze (char maze[][MAX]) {
    int i;
    for (i = 0; i < MAX; i++) {
        cin >> maze[i];
    }
}

void print_maze (char maze[][MAX]) {
    int i,d;
    for (i = 0; i < MAX; i++) {
        for (d = 0; d < MAX; d++) {
            cout << maze[i][d];
        }
        cout << endl;
    }
}

int contains(list<coords_t*> *arr, coords_t other) {
    list<coords_t*>::iterator iterator;
    for (iterator = arr->begin(); iterator != arr->end(); ++iterator) {
        if (**iterator == other) return 1;
    }
    return 0;
}

void scan_neighbours (list<coords_t*> *open, list<coords_t*> *close, char maze[][MAX],
                      coords_t* current, coords_t start, coords_t end) {
    // TODO: Finish up the scanning for shortest path
    int y = current->y, x = current->x;
    if (y+1 < MAX) {
        coords_t *neighbour = new coords_t;
        neighbour->x = x;
        neighbour->y = y+1;
        neighbour->g_cost = cartesian_count(x, y+1, start.x, start.y);
        neighbour->h_cost = cartesian_count(x, y+1, end.x, end.y);
        neighbour->parent = current;
        if (!contains(open, *neighbour) && !contains (close, *neighbour) && maze[y+1][x] != '@') {
            open->push_back(neighbour);
        }
    }
    if (y-1 >= 0) {
        coords_t *neighbour = new coords_t;
        neighbour->x = x;
        neighbour->y = y-1;
        neighbour->g_cost = cartesian_count(x, y-1, start.x, start.y);
        neighbour->h_cost = cartesian_count(x, y-1, end.x, end.y);
        neighbour->parent = current;
        if (!contains(open, *neighbour) && !contains (close, *neighbour) && maze[y-1][x] != '@') {
            open->push_back(neighbour);
        }
    }
    if (x-1 >= 0) {
        coords_t *neighbour = new coords_t;
        neighbour->x = x-1;
        neighbour->y = y;
        neighbour->g_cost = cartesian_count(x-1, y, start.x, start.y);
        neighbour->h_cost = cartesian_count(x-1, y, end.x, end.y);
        neighbour->parent = current;
        if (!contains(open,*neighbour) && !contains (close, *neighbour) && maze[y][x-1] != '@') {
            open->push_back(neighbour);
        }
    }
    if (x+1 < MAX) {
        coords_t *neighbour = new coords_t;
        neighbour->x = x+1;
        neighbour->y = y;
        neighbour->g_cost = cartesian_count(x+1, y, start.x, start.y);
        neighbour->h_cost = cartesian_count(x+1, y, end.x, end.y);
        neighbour->parent = current;
        if (!contains(open, *neighbour) && !contains (close, *neighbour) && maze[y][x+1] != '@') {
            open->push_back(neighbour);
        }
    }
}

int pathfinder (list<coords_t*> *open, list<coords_t*> *close, coords_t start, coords_t end, char maze[][MAX]) {
    // Can only travel 4 directions
    while (open->size() > 0) {
        coords_t *current = open->front();
        // Sorting
        list<coords_t*>::iterator iterator;
        for (iterator = open->begin(); iterator != open->end(); ++iterator) {
            if (current->h_cost + current->g_cost > (*iterator)->g_cost + (*iterator)->h_cost) {
                current = *iterator; // Set current to node with the lowest f_cost
            }else if (current->h_cost + current->g_cost == (*iterator)->g_cost + (*iterator)->h_cost &&
                      current->h_cost > (*iterator)->h_cost) {
                // If they have the same f_cost
                current = *iterator;
            }
        }
        
        close->push_back(current);
        // pop(open, current);
        open->remove(current);
        if (current->x == end.x && current->y == end.y) {
            return 1; // Path has been found
        }
        scan_neighbours (open, close, maze, current, start, end);
    }
    return 0;
}



void start_end_scan (coords_t *start, coords_t *end, char maze[][MAX]) {
    int i, d;
    for (i = 0; i < MAX; i++) {
        for (d = 0; d < MAX; d++) {
            if (maze[i][d] == 's') {
                start-> x = d;
                start-> y = i;
            }
            if (maze[i][d] == 'e') {
                end-> x = d;
                end-> y = i;
            }
        }
    }
    start->g_cost = 0;
    start->h_cost = cartesian_count(start->x, start->y, end->x, end->y);
    end->h_cost = 0;
    end->g_cost = cartesian_count(start->x, start->y, end->x, end->y);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char maze[MAX][MAX];
    list<coords_t*> open;
    list<coords_t*> closed;
    coords_t *start = new coords_t;
    coords_t *end = new coords_t;
    scan_maze(maze);
    cout << "Original Maze:" << endl;
    print_maze(maze);
    start_end_scan(start, end, maze);
    
    // Initial run
    scan_neighbours (&open, &closed, maze, start, *start, *end);
    pathfinder(&open, &closed, *start, *end, maze);
    
    // Traceback
    maze[end->y][end->x] = '*';
    coords_t* current_point;
    // Search for end point (find end node)
    list<coords_t*>::iterator iterator;
    for (iterator = closed.begin(); iterator != closed.end(); ++iterator) {
        if ((*iterator)->x == end->x && (*iterator)->y == end->y) {
            current_point = *iterator;
        }
    }
    // Iterate thru the next few
    while (current_point->x != start->x || current_point->y != start->y) {
        // Continue tracing
        current_point = current_point->parent;
        maze[current_point->y][current_point->x] = '*';
    }
    cout << "Shortest path:" << endl << endl;
    print_maze (maze);
    
    
    return 0;
}
