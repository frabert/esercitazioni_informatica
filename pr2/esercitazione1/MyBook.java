public class MyBook implements Book {
    private String author, title, publisher;
    private int year;

    public MyBook(String author, String title, String publisher, int year) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.year = year;
    }

    public String getAuthor() { return author; }
    public String getTitle() { return title; }
    public String getPublisher() { return publisher; }
    public int getYear() { return year; }

    public boolean sameAuthor(Book b) {
        return author.equals(b.getAuthor());
    }

    public boolean sameTitle(Book b) {
        return title.equals(b.getTitle());
    }

    public boolean samePublisher(Book b) {
        return publisher.equals(b.getPublisher());
    }

    public boolean sameYear(Book b) {
        return year == b.getYear();
    }

    public boolean sameWork(Book b) {
        return sameAuthor(b) && sameTitle(b);
    }

    public boolean equals(Book b) {
        return sameWork(b) && samePublisher(b) && sameYear(b);
    }
}