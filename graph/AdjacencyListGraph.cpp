
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int edgeNo;
    int weight;
    Edge() {};
    Edge(int edgeNo, int weight) {
        this->edgeNo = edgeNo;
        this->weight = weight;
    }
};

class AdjacencyListGraph {
    private:
        size_t numberOfVertex;
        vector<vector<Edge> > *graph;
    public:
        AdjacencyListGraph(size_t n) {
            numberOfVertex = n+1;
            graph = new vector<vector<Edge> >(numberOfVertex, vector<Edge>());
        }

        ~AdjacencyListGraph() {
            free(graph);
        }

        void addDirectedEdge(int startVertex, int endVertex, int weight) {
            Edge newEdge(endVertex, weight);
            graph->at(startVertex).push_back(newEdge);
        }

        void addUndirectedEdge(int firstEdge, int secondEdge, int weight = 1) {
            addDirectedEdge(firstEdge, secondEdge, weight);
            addDirectedEdge(secondEdge, firstEdge, weight);
        }

        void showGraph() {
            for(int i=0; i<=numberOfVertex; i++) {
                cout << i << ": ";
                for(auto e: graph->at(i)) {
                    cout << "{" << e.edgeNo << ", " << e.weight << "}, ";
                }
                cout << endl;
            }
        }

        // accepted https://www.spoj.com/problems/SHPATH/
        pair<int64_t, stack<int> > shortest(size_t startVertex, size_t endVertex) {
            vector<int64_t> d(numberOfVertex + 1, INT64_MAX);
            vector<int> trace(numberOfVertex + 1, -1);
            vector<bool> isVisited(numberOfVertex + 1, false);
            stack<int> result;

            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int> >, greater<pair<int64_t, int> > > pq;

            d[startVertex] = 0;

            pq.push({0, startVertex});

            while(!pq.empty()) {
                int u = pq.top().second;
                if(u == endVertex) {
                    while(u != -1) {
                        result.push(u);
                        u = trace[u];
                    }
                    return {pq.top().first, result};
                }
                pq.pop();

                for(Edge e: graph->at(u)) {
                    int v = e.edgeNo;
                    int w = e.weight;

                    if(d[v] > d[u] + w) {
                        d[v] = d[u] + w;
                        pq.emplace(d[v], v);
                        trace[v] = u;
                    }
                }
            }

            return {d[endVertex], result};
        }
        
};


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt","r", stdin);
	
    int T; cin>>T;
    while(T--) {
        unordered_map<string, int> name;
        int n; cin>>n;
        AdjacencyListGraph g(n);
        
        for(int i=1; i<=n; i++) {
            string s; cin>>s;
            name[s] = i;
            int p; cin>>p;
            for(int j=0; j<p; j++) {
                int v, w; cin >> v>>w;
                g.addUndirectedEdge(i, v, w);
            }
        }

        int p; cin>>p;
        while(p--) {
            string s;
            int u, v;
            cin>>s; u = name[s];
            cin>>s; v = name[s];
            
            auto res = g.shortest(u, v);
            cout << res.first << endl;;
        }
    }
    return 0;
}