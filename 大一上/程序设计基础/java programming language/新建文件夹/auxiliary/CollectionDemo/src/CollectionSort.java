import java.io.File;
import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;


public class CollectionSort {
	
	public static void main(String args[]){
		new CollectionSort().ListSort();
	}
	
	public void ListSort(){
		List<Student> stuList = ReadStudent();
		Collections.sort(stuList);
		System.out.println(stuList);
	}
	
	public List<Student> ReadStudent(){
		List<Student> stuList = new ArrayList<Student>();
		try{
			File file = new File("score.txt");
			BufferedReader bf = new BufferedReader(new FileReader(file));
			String line = null;
			while((line = bf.readLine())!=null){
				String[] OneStu = line.split("/");
				Student stu = new Student(OneStu[0],OneStu[1],Integer.parseInt(OneStu[2]));
				stuList.add(stu);			
			}
		}catch(IOException e){
			e.printStackTrace();
		}
		
		return stuList;
		
		
	}

}
