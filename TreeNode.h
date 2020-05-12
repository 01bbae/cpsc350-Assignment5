template<typename T>
class TreeNode{
public:
  TreeNode();
  TreeNode(int key, T value);
  ~TreeNode();
  TreeNode* left;
  TreeNode* right;
  int key;
  T value;
};

template<typename T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
  key = 0;
  value = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(int key, T value){
  left = NULL;
  right = NULL;
  this->key = key;
  this->value = value;
}

template<typename T>
TreeNode<T>::~TreeNode(){
  //delete
}
