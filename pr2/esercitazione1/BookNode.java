public class BookNode {
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