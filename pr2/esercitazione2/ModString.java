// OVERVIEW: Una ModString è una stringa modificabile
//   di dimensione qualunque.
public interface ModString {
    // EFFECTS: ritorna la lunghezza della stringa
    public int size();

    // REQUIRES: num < this.size
    // EFFECTS: sostituisce il carattere in posizione num con c
    public void update(char c, int num);

    // REQUIRES: num < this.size
    // EFFECTS: sia this_pre = [c_1 ... c_(num - 1)] + c_num + [c_(num + 1) ... c_size],
    //   allora this_post = [c_1 ... c_(num - 1)] + [c_(num + 1) ... c_size]
    public void remove(int num);
}