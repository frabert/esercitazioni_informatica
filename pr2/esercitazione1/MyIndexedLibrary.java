public class MyIndexedLibrary extends MyLibrary implements IndexedLibrary {
    private int lastidx;

    public MyIndexedLibrary() {
        lastidx = 1;
    }

    public IndexedBook getByIndex(int index) throws Exception {
        int n = list.getLength();
        for(int i = 0; i < n; i++) {
            if(((IndexedBook)(list.getValue(i))).getIndex() == index) {
                return (IndexedBook)list.getValue(i);
            }
        }
        throw new Exception("Elemento non trovato");
    }
    
    public void insert(Book b) {
        list.insert(new MyIndexedBook(b, lastidx));
        lastidx++;
    }

    public void remove(int index) throws Exception {
        int n = list.getLength();
        for(int i = 0; i < n; i++) {
            if(((IndexedBook)(list.getValue(i))).getIndex() == index) {
                list.remove(list.getValue(i));
            }
        }
        throw new Exception("Elemento non trovato");
    }
}