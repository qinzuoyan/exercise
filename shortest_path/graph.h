#ifndef  __GRAPH_H_
#define  __GRAPH_H_

#include <map>
#include <set>
#include <list>
#include <climits>

template<typename T>
class Graph {
    std::map<T, std::list<std::pair<T, int>>> l;

public:
    void addEdge(T x, T y, int wt) {
        l[x].push_back({y, wt});
        l[y].push_back({x, wt});
    }

    // return INT_MAX if not reachable
    int djikstraShortestPath(T src, T dst) {
        map<T, int> dist;
        djikstraShortestPath(src, dist, &dst);
        auto pr = dist.find(dst);
        return pr == dist.end() ? INT_MAX : pr->second;
    }

    // set to INT_MAX if not reachable
    void djikstraShortestPath(T src, map<T, int>& dist, const T* dst = nullptr) {
        // Initialising dist to inf
        dist.clear();
        for (auto p : l) {
            T node = p.first;
            dist[node] = INT_MAX;
        }
        dist[src] = 0;

        // set created to get the min dist element at the beginning
        //         dist, node
        set<pair<int, T>> s;
        s.insert({0, src});

        while (!s.empty()) {
            pair<int, T> p = *s.begin();
            if (dst && *dst == p.second) {
                return;
            }
            s.erase(s.begin());
            T currNode = p.second;
            int currNodeDist = p.first;

            // visit all nbrs of node
            for (auto nbr : l[currNode]) {
                T nbrNode = nbr.first;
                int distInBetween = nbr.second;
                int nbrNodeDist = dist[nbrNode];

                // Potential new distance = currNodeDist + distInBetween
                if (currNodeDist + distInBetween < nbrNodeDist) {

                    // Update dist in both set and map
                    // If node not present in set then add it
                    auto pr = s.find({dist[nbrNode], nbrNode});
                    if (pr != s.end()) {
                        s.erase(pr);
                    }
                    dist[nbrNode] = currNodeDist + distInBetween;
                    s.insert({dist[nbrNode], nbrNode});
                }
            }
        }
    }
};

#endif
