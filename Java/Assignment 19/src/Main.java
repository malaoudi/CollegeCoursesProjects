
public class Main {

	public static void main(String[] args) {
		double north = 20;
		double south = 25 ;
		double east = 15;
		double west = 35;
		double midWest = 10;
		
		//constructor
		JFrameExt f = new JFrameExt(north,south,east,west,midWest);
		f.setSize(600,600);
		f.setVisible(true);
			
	}

}
