class X {
    String info = null;
    X x = null;
    X(String s) {
        info = s;
    }
}

class Y extends X {
    static Y last = null;
    Y(String s, X newXX) {
        super(s);
        x = newXX;
        last = this;
    }
}

public class GcQuiz2 {
    static X x = new X("Ç†");
    Y y = new Y("Ç¢", x);
    public static void main(String[] args) {
        X[] a = new X[3];
        a[0] = new X("Ç§");
        a[1] = new Y("Ç¶", a[0]);
        a[2] = new Y("Ç®", new X("Ç©"));
        if(new X("Ç´") == new X("Ç´")) {
            a[2] = new X("Ç≠");
        } else {
            a[2] = a[1];
        }
        if(new Y("ÇØ", x) instanceof X) {
            a[0] = new X("Ç±");
        }
        a[1] = null;
        System.gc();
        // Å¶Ç±ÇÃéûì_
    }
}
