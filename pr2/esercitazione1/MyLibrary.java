public class MyLibrary implements Library {
    protected BookList list;

    public MyLibrary() {
        list = new BookList();
    }

    public String[] getByAuthor(String aut) {
        BookList newList = new BookList();
        int listLength = list.getLength();
        int newListLength = 0;
        for(int i = 0; i < listLength; i++) {
            Book b = list.getValue(i);
            if(b.getAuthor().equals(aut)) {
                newList.insert(b);
                newListLength++;
            }
        }

        String[] res = new String[newListLength];
        for(int i = 0; i < newListLength; i++) {
            res[0] = newList.getValue(i).getTitle();
        }

        return res;
    }

    public String[] getByTitle(String aut) {
        BookList newList = new BookList();
        int listLength = list.getLength();
        int newListLength = 0;
        for(int i = 0; i < listLength; i++) {
            Book b = list.getValue(i);
            if(b.getTitle().equals(aut)) {
                newList.insert(b);
                newListLength++;
            }
        }

        String[] res = new String[newListLength];
        for(int i = 0; i < newListLength; i++) {
            res[0] = newList.getValue(i).toString();
        }

        return res;
    }

    public String[] getByPublisher(String aut) {
        BookList newList = new BookList();
        int listLength = list.getLength();
        int newListLength = 0;
        for(int i = 0; i < listLength; i++) {
            Book b = list.getValue(i);
            if(b.getPublisher().equals(aut)) {
                newList.insert(b);
                newListLength++;
            }
        }

        String[] res = new String[newListLength];
        for(int i = 0; i < newListLength; i++) {
            res[0] = newList.getValue(i).toString();
        }

        return res;
    }

    public String[] getByYear(int year) {
        BookList newList = new BookList();
        int listLength = list.getLength();
        int newListLength = 0;
        for(int i = 0; i < listLength; i++) {
            Book b = list.getValue(i);
            if(b.getYear() == year) {
                newList.insert(b);
                newListLength++;
            }
        }

        String[] res = new String[newListLength];
        for(int i = 0; i < newListLength; i++) {
            res[0] = newList.getValue(i).toString();
        }

        return res;
    }

    public String[] getAuthorByPublisher(String pub) {
        BookList newList = new BookList();
        int listLength = list.getLength();
        int newListLength = 0;
        for(int i = 0; i < listLength; i++) {
            Book b = list.getValue(i);
            if(b.getPublisher().equals(pub)) {
                newList.insert(b);
                newListLength++;
            }
        }

        String[] res = new String[newListLength];
        for(int i = 0; i < newListLength; i++) {
            res[0] = newList.getValue(i).getAuthor();
        }

        return res;
    }

    public String[] getTitleByYear(int year) {
        BookList newList = new BookList();
        int listLength = list.getLength();
        int newListLength = 0;
        for(int i = 0; i < listLength; i++) {
            Book b = list.getValue(i);
            if(b.getYear() == year) {
                newList.insert(b);
                newListLength++;
            }
        }

        String[] res = new String[newListLength];
        for(int i = 0; i < newListLength; i++) {
            res[0] = newList.getValue(i).getTitle();
        }

        return res;
    }

    public void remove(Book b) throws Exception {
        list.remove(b);
    }

    public void insert(Book b) {
        list.insert(b);
    }
}