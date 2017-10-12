import java.util.Scanner;
import java.util.Vector;

public class TestModStringCollection {
    private static String last = new String("fine");
    private static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        ModStringCollection coll = new MyModStringCollection();
        String str; int num;

        System.out.println("digita le stringhe da inserire con \"" +last+ "\" per terminare");
        str = input.nextLine( );
        
        while(!(str.equals(last))){
            coll.insert(new MyModString(str));
            str = input.nextLine( );
        }
        
        System.out.println("abbiamo inserito " +coll.size()+ " stringhe");
        
        printUnique(coll);
        
        System.out.println("dimmi quale stringa vuoi eliminare");
        str = input.nextLine();

        System.out.println("dimmi quante occorrenze vuoi eliminare della stringa \"" +str+ "\"");
        num = input.nextInt();
        
        try {
            System.out.println("eliminate " +coll.remove(new MyModString(str), num)+ " occorrenze di \"" +str+ "\"");
        }
        catch (Exception e) { System.out.println("errore"); };
        
        printUnique(coll);
    }
    
    private static void printUnique(ModStringCollection c) {
        String[] uni = c.getUnique();
        ModString mstr;
        
        System.out.println("ci sono " +uni.length + " elementi senza duplicati");
        System.out.println("questa e' la lista con le relative occorrenze");
        
        for(int i = 0; i < uni.length; i++) {
            mstr = new MyModString(uni[i]);
            System.out.println("\"" +uni[i]+ "\" occorre " +c.occurrences(mstr)+ " volte");
        }
    }
}