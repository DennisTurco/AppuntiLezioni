package binarytree;

public class BinaryTree {
    private Node<Integer> root; 

    // la add e' quella che viene chiamata dal main
    public void add(int value) {
        root = addRecursive(root, value);
    }

    // questa viene chiamata solo dalla add
    private Node<Integer> addRecursive(Node<Integer> currentNode, Integer value) {
        if (currentNode == null) return new Node<>(value);

        if (value < currentNode.value) {
            currentNode.left = addRecursive(currentNode.left, value);
        } else if (value > currentNode.value) {
            currentNode.right = addRecursive(currentNode.right, value);
        } else { // caso in cui sono uguali (non aggiungiamo nulla)
            return currentNode;
        }

        return currentNode;
    }

    // esistono anche altre funzioni per spostarsi fra i nodi (ho scelto la piu' semplice per questo esempio)
    public void traversePreOrder(Node<Integer> node) {
        if (node != null) {
            System.out.print(" " + node.value);
            traversePreOrder(node.left);
            traversePreOrder(node.right);
        }
    }

    // ottengo la radice dell'albero
    public Node<Integer> getRoot() {
        return root;
    }
}
