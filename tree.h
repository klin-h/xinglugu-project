#ifndef TREE_H
#define TREE_H
#include "SceneObject.h"


class Tree : public SceneObject {
public:
    static Tree* create(const std::string& filename);

    InteractResult interact() override; // ʵ�ֽ����߼�
    
private:

};

#endif // TREE_H
