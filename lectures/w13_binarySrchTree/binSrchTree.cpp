#include "binSrchTree.hpp"

int main(){
    BinSrchTree tree;

    // 삽입 연산 테스트
    tree.insert(new BinaryNode(35));
    tree.insert(new BinaryNode(18));
    tree.insert(new BinaryNode(7));
    tree.insert(new BinaryNode(26));
    tree.insert(new BinaryNode(12));
    tree.insert(new BinaryNode(3));
    tree.insert(new BinaryNode(68));
    tree.insert(new BinaryNode(22));
    tree.insert(new BinaryNode(30));
    tree.insert(new BinaryNode(99));

    std::cout << "노드의 수: " << tree.getCount() << "\n";
    std::cout << "단말의 수: " << tree.getLeafCount() << "\n";
    std::cout << "트리의 높이: " << tree.getHeight() << "\n";

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    tree.search(26);
    tree.search(25);

    // 삭제 연산 테스트
    std::cout << "삭제 case 1: 노드 3 삭제\n";
    tree.remove(3);//자식이 없는 경우
    tree.inorder();
    std::cout << "삭제 case 2: 노드 68 삭제\n";
    tree.remove(68);//한쪽에만 자식 존재하는 경우
    tree.inorder();
    std::cout << "삭제 case 3: 노드 18 삭제\n";
    tree.remove(18);//양쪽 다 자식 존재하는 경우, 18지우면 대체로 22번이 들어감
    tree.inorder();
    std::cout << "삭제 case 3: 노드 35 (루트 노드) 삭제\n";
    tree.remove(35);//35번이 root, root지우기
    tree.inorder();

    // 최종 트리 정보 출력
    std::cout << "노드의 수: " << tree.getCount() << "\n";
    std::cout << "단말의 수: " << tree.getLeafCount() << "\n";
    std::cout << "트리의 높이: " << tree.getHeight() << "\n";
    return 0;
}