public interface ModStringCollection {
    public int occurrences(ModString s);
    public int size();
    public void insert(ModString s);
    public int remove(ModString s, int num);
    public String[] getUnique();
}