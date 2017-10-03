public class MyIndexedBook extends MyBook implements IndexedBook {
    private int index;
    private String genre;

    public MyIndexedBook(Book b, int index) {
        this(b.getAuthor(), b.getTitle(), b.getPublisher(), b.getYear(), index, "");
    }

    public MyIndexedBook(String author, String title, String publisher, int year, int index, String genre) {
        super(author, title, publisher, year);
        this.index = index;
        this.genre = genre;
    }

    public int getIndex() { return index; }
    public String getGenre() { return genre; }

    public boolean sameGenre(IndexedBook b) {
        return genre.equals(b.getGenre());
    }
}