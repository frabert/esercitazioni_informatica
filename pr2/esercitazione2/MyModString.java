import java.util.Vector;

public class MyModString implements ModString {
    // Rep invariant: charElts contiene nelle prime m_size posizioni
    //   i caratteri non nulli della stringa.
    //   m_size non può eccedere la dimensione di charElts.

    // AF(MyModString this) = <charElts.get(0)>, ... charElts.get(m_size - 1)>
    private final char[] charElts;
    private int m_size;

    // REQUIRES: s 
    // EFFECTS: crea una nuova MyModString inizializzata con i caratteri di s
    //   la cui lunghezza potrà essere al massimo quella di s
    public MyModString(String s) {
        charElts = s.toCharArray();
        m_size = s.length();
    }

    // EFFECTS: restituisce la lunghezza della stringa
    public int size() {
        return m_size;
    }

    // MODIFIES: this
    // REQUIRES: num < this.size()
    // EFFECTS: il carattere in posizione num ora è c
    public void update(char c, int num) {
        charElts[num] = c;
    }

    // MODIFIES: this
    // REQUIRES: num < this.size()
    // EFFECTS: rimuove il carattere in posizione num dalla stringa,
    //   eventualmente riposizionando il resto dei caratteri
    public void remove(int num) {
        for(int i = num; i < m_size - 1; i++) {
            charElts[i] = charElts[i + 1];
        }
        m_size--;
    }

    public String toString() {
        return new String(charElts, 0, m_size);
    }

    public boolean equals(Object s) {
        return s.toString().equals(toString());
    }
}