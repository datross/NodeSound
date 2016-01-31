/* graph.hpp */

#ifndef GRAPH
#define GRAPH

#include "core/node.hpp"
#include "core/wrappedConnectionTypes.hpp"
#include <vector>

// identifie un NodeHost et un numéro de connexion

typedef struct HostAndConnection HostAndConnection;


// hôte d'un noeud, avec toutes les connexions enregistrées

typedef struct NodeHost {
    unsigned id; // identifiant, permet de le reconnaître entre tous
    Node * node; // pointeur vers le "vrai" noeud
    std::vector< std::vector<HostAndConnection*> > in, out;
}
    
HostAndConnection {
    NodeHost * node;
    int connection;
}

// graphe de noeuds

class Graph {
    public:
        Graph();
        ~Graph();
        
        NodeHost * getHost(unsigned id); // clair
        unsigned addNode(Node * node); // returns node's id
        
        void connect(unsigned id_1, int connection_1, unsigned id_2, int connection_2); // connecte 1 à 2 avec les ports id_1 et id_2. connection_1 doit être > 0 et inversement pour connection_2
        void disconnect(unsigned id_1, int connection_1, unsigned id_2, int connection_2); // même manière que connect().
    private:
        std::vector<NodeHost*> graph;
};

#endif // GRAPH
