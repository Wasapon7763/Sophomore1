
public class ExceptionHomework {

	static int number(String s) throws OriginalException{
		try {
			System.out.println("try");
			return Integer.parseInt(s);
		} catch(NumberFormatException nfe) {
			System.out.println("catch");
			throw new OriginalException();
		} finally {
			System.out.println("finally");
		}
	}

	public static void main(String[] args) {
		try{
			System.out.println(number("10"));
			System.out.println(number("XXXXXXXXX"));
		}
		catch (OriginalException oe){
			System.out.println(oe);
		}
	}

}
