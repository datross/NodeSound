/* node.hpp */

#ifndef NODE
#define NODE


/*
 * NOTE : pour indexer les connexions d'un noeud, un nombre positif pour les sortante, et négatif pour les entrante. 0 n'est PAS utilisé.
 */

typedef enum connectionType {
    U_AUDIO,
    W_AUDIO,
    U_MIDI,
    W_MIDI,
    U_NBR
} connectionType;

class Node {
    public:
        Node();
        
        virtual connectionType getConnectionType(int connecton); // retourne le type de la connexion.
        virtual unsigned getConnectionInNbr(); // clair
        virtual unsigned getConnectionOutNbr(); // idem
        
        virtual void setInData(int connection, void * data); // clair
        virtual void process(float time); // le noeud prépare toutes les sorties | 'time' est le temps actuel dans le référentiel du noeud de rendu le plus proche
        virtual void * getOutData(int connection); // pour avoir les sorties
    private:
};

#endif
