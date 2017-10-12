import java.util.Vector;

public class MyModStringCollection implements ModStringCollection {
    // Rep invariant: str contiene gli elementi contenuti nella collezione senza duplicati.
    //   occ[i] = #{ s }
    private final Vector<ModString> str;
    private final Vector<Integer> occ;

    // EFFECTS: Crea una nuova MyModStringCollection vuota
    public MyModStringCollection() {
        str = new Vector<ModString>();
        occ = new Vector<Integer>();
    }
    
    // REQUIRES: s != null
    // EFFECTS: restituisce il numero di occorrenze di s nella collezione
    public int occurrences(ModString s) {
        int index = str.indexOf(s);
        if(index < 0) {
            return 0;
        } else {
            return occ.get(index);
        }
    }

    // EFFECTS: ritorna la quantità di stringhe contenute
    public int size() {
        int total = 0;
        for(int i = 0; i < str.size(); i++) {
            total += occ.get(i);
        }
        return total;
    }

    // REQUIRES: s != null
    // EFFECTS: aggiunge s alla collezione
    public void insert(ModString s) {
        int index = str.indexOf(s);
        if(index < 0) {
            str.add(s);
            occ.add(1);
        } else {
            int numOcc = occ.get(index);
            occ.set(index, numOcc + 1);
        }
    }
    
    // REQUIRES: s != null
    // EFFECTS: Rimuove al più num occorrenze di s, o tutte se num = 0
    public int remove(ModString s, int num) {
        int index = str.indexOf(s);
        if(index >= 0) {
            int numOcc = occ.get(index);
            if(num == 0 || num > numOcc) {
                int o = occ.remove(index);
                ModString t = str.remove(index);
                return numOcc;
            } else {
                occ.set(index, numOcc - num);
                return num;
            }
        } else {
            return 0;
        }
    }

    // EFFECTS: Restituisce gli elementi della collezione eliminando i duplicati.
    public String[] getUnique() {
        String[] tmp = new String[str.size()];
        for(int i = 0; i < str.size(); i++) {
            tmp[i] = str.get(i).toString();
        }
        return tmp;
    }
}