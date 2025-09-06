package binarytree;

public class Node<T> {
    protected T value;
    protected Node<T> left;
    protected Node<T> right;

    public Node(T value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    public boolean hasLeft() {
        return left != null;
    }

    public boolean hasRight() {
        return right != null;
    }
}
