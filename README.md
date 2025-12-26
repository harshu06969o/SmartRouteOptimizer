# Adaptive Route Optimizer using Graph Algorithms

This project implements a constraint-aware route optimization system using core graph algorithms primarily Dijkstra's algorithm.

The goal is to compute optimal paths between locations while handling real-world constraints like blocked nodes and dynamic routing conditions.

## Key Features
- Graph-based modeling using adjacency lists
- Shortest path computation using Dijkstra’s algorithm
- Support for blocked nodes and edges
- Extensible design for multi-source route optimization
- Path reconstruction (actual route, not just distance)

## Technologies Used
- C++
- Graph Algorithms
- Priority Queues
- Standard Template Library (STL)

 ## Design Decisions
- Used adjacency lists to efficiently represent sparse graphs
- Selected Dijkstra’s algorithm to handle weighted routes correctly
- Explicitly handled blocked nodes to simulate real-world constraints
- Reconstructed paths to return actual routes, not just distances

---

## Time Complexity
- **Dijkstra’s Algorithm:**  
  O((V + E)log V) , where  
  - \( V \) is the number of locations (nodes)  
  - \( E \) is the number of roads (edges)  

This ensures efficient performance even for larger and sparse road networks.



## Space Complexity
O(V + E)

Where:
- **V** is the number of locations (nodes)
- **E** is the number of roads (edges)

Space is used by:
- Adjacency list representation of the graph → O(E)
- Distance, parent, and blocked arrays → O(V)
- Priority queue in the worst case → O(V)

---

## Example Usage

This example demonstrates how the Adaptive Route Optimizer computes the
shortest valid route while handling real-world constraints such as blocked
locations.


### Sample Input
```
Enter number of locations: 5 
Enter number of roads: 6
Enter roads (from to distance): 
0 1 2 
1 2 3 
0 3 6 
3 4 2
4 2 1
1 4 4
Enter number of blocked locations: 1 
Enter blocked locations: 3
Enter start location: 0 
Enter destination: 2
```

### Sample Ouput
Optimal Route 0->1->2

### Explanation
- The map contains 5 locations connected by weighted roads.
- Location `3` is blocked, so any path passing through it is ignored.
- The algorithm uses Dijkstra’s algorithm to compute the shortest valid path.
- The final route avoids blocked locations while minimizing total distance.


## Status
Core functionality complete.Future improvements planned.
