/* graph.cpp */

#include "core/graph.hpp"
#include <cstdlib>

Graph::Graph() {
}

NodeHost * Graph::getHost(unsigned id) {
    // Recherche par dichotomie, on suppose qu'ils sont triés par ordre croissant d'identifiant
    
    unsigned begin = 0, end = graph.size() - 1, mid;
    
    while(begin <= end) {
        mid = (end + begin) / 2;
        if(graph[i]->id == id)
            return graph[i];
        if(graph[i]->id > id) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return NULL;
}

Graph::~Graph() {
    unsigned i = 0, j, k;
    for(; i < graph.size(); ++i) {
        // les entrées
        j = 0;
        for(; j < graph[i]->in.size(); ++j) {
            k = 0;
            for(; k < graph[i]->in[j].size(); ++k) {
                delete graph[i]->in[j][k];
            }
        }
        // et les sorties
        j = 0;
        for(; j < graph[i]->out.size(); ++j) {
            k = 0;
            for(; k < graph[i]->out[j].size(); ++k) {
                delete graph[i]->out[j][k];
            }
        }
        delete graph[i];
    }
}

unsigned Graph::addNode(Node * node) {
    NodeHost * host = new NodeHost;
    host->node = node;
    
    // on lui donne le plus petit identifiant libre
    for(host->id = 0;; host->id < graph.size() && host->id == graph[host->id]->id; ++(host->id));

    graph.insert(graph.begin() + host->id, host);
    
    return host->id;
}

void Graph::connect(unsigned id_1, int connection_1, unsigned id_2, int connection_2) {
    NodeHost * h_1 = getHost(id_1), * h_2 = getHost(id_2);
    
    // petite verif d'existence des hôtes
    if(!h_1 || !h_2)
        return;
        
    // on vérifie si la connexion n'existe pas déjà
    unsigned i = 0;
    for(; i < h_1->out[connection_1 - 1].size(); ++i) {
        if(h_1->out[connection_1 - 1][i]->node->id == id_2 && h_1->out[connection_1 - 1][i]->node->connection == connection_2)
            return;
    }
    
    // si c'est bon on l'ajoutte
    HostAndConnection * _1 = new HostAndConnection;
    _1->node = h_2;
    _1->connection = connection_2;
    h_1->out[connection_1 - 1].push_back(_1);
    
    HostAndConnection * _2 = new HostAndConnection;
    _2->node = h_1;
    _2->connection = connection_1;
    h_2->in[-1 - connection_2].push_back(_2);
}

void Graph::disconnect(unsigned id_1, int connection_1, unsigned id_2, int connection_2) {
    NodeHost * h_1 = getHost(id_1), * h_2 = getHost(id_2);
    
    // petite verif d'existence des hôtes
    if(!h_1 || !h_2)
        return;
        
    unsigned i;
    
    for(i = 0; i < h_1->out[connection_1 - 1].size() && !(h_1->out[connection_1 - 1][i]->node->id == id_2 && h_1->out[connection_1 - 1][i]->node->connection == connection_2); ++i);
    if(i == h_1->out[connection_1 - 1].size()) // si elle n'existe pas
        return;
    delete h_1->out[connection_1 - 1][i];
    h_1->out[connection_1 - 1].erase(h_1->out[connection_1 - 1].begin() + i);
    
    for(i = 0; i < h_2->in[-1 - connection_2].size() && !(h_2->in[-1 - connection_2][i]->node->id == id_1 && h_2->in[-1 - connection_2][i]->node->connection == connection_1); ++i);
    if(i == h_2->in[-1 - connection_2].size()) // si elle n'existe pas
        return;
    delete h_2->in[-1 - connection_2][i];
    h_2->in[-1 - connection_2].erase(h_2->in[-1 - connection_2].begin() + i);
}
