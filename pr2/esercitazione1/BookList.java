public class BookList {
    private class BookNode {
        private Book bk;
        private BookNode next;

        public BookNode(Book value, BookNode next) {
            bk = value;
            this.next = next;
        }

        public Book getValue() { return bk; }
        public BookNode getNext() { return next; }

        public void setNext(BookNode n) {
            next = n;
        }

        public int getLength() {
            if(next == null) {
                return 1;
            } else {
                return 1 + next.getLength();
            }
        }
    }

    private BookNode start;

    public BookList() {}

    public void insert(Book b) {
        BookNode ptr = start;
        BookNode prev = null;
        BookNode node = new BookNode(b, null);
        while(ptr != null) {
            prev = ptr;
            ptr = ptr.next;
        }

        if(prev == null) {
            start = node;
        } else {
            prev.setNext(node);
        }
    }

    public void remove(Book b) throws Exception {
        boolean removed = false;
        while(start != null && start.getValue().equals(b)) {
            start = start.next;
            removed = true;
        }

        BookNode ptr = start.next, prev = start;
        while(ptr != null) {
            if(ptr.getValue().equals(b)) {
                prev.next = ptr.next;
                removed = true;
            }
            prev = ptr;
            ptr = ptr.next;
        }

        if(!removed) {
            throw new Exception("Elemento non trovato");
        }
    }

    public int getLength() {
        int len = 0;
        BookNode ptr = start;
        while(ptr != null) {
            len++;
            ptr = ptr.next;
        }
        return len;
    }

    public Book getValue(int index) throws java.lang.IndexOutOfBoundsException {
        BookNode ptr = start;
        while(index > 0 && ptr != null) {
            ptr = ptr.next;
            index--;
        }

        if(ptr == null) {
            throw new java.lang.IndexOutOfBoundsException();
        } else {
            return ptr.getValue();
        }
    }
}