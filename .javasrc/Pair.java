class Pair<X,Y>  { 
    private X first;
    private Y second;

    public Pair(X a1, Y a2) {
        first  = a1;
        second = a2;
    }
    
    public X getFirst()  { return first; }
    public Y getSecond() { return second; }
    public void setFirst(X arg)  { first = arg; }
    public void setSecond(Y arg) { second = arg; }
}