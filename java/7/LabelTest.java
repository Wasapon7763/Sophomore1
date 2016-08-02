public class LabelTest {
    public static void main(String[] args) {
        Label.common = "図";
        Label l1 = new Label("人口の比較");
        Label l2 = new Label("生産量の傾向");
        l1.output();
        l2.output();
        Label.common = "表";
        l1.output();
        l2.output();
    }
}