
public class Student implements Comparable<Student> {

	String name;
	String sex;
	int score;
	

	
	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public String getSex() {
		return sex;
	}


	public void setSex(String sex) {
		this.sex = sex;
	}


	public int getScore() {
		return score;
	}

	public void setScore(int score) {
		this.score = score;
	}


	public Student(String name, String sex, int score) {
		super();
		this.name = name;
		this.sex = sex;
		this.score = score;
	}

	@Override
	public int compareTo(Student o) {
		
		return o.score-this.score;
	}
	
	@Override
	public String toString(){
		return this.name+"-"+this.score;
	}

}
