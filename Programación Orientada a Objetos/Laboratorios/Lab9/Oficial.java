public class Oficial{

    private String name;
    private int numOficial;

    
    public Oficial(){
        this.name=" ";
        this.numOficial= 0;

    }

    public Oficial(String name,int numOficial){

        this.name=name;
        this.numOficial=numOficial;
    }
    public  String getName(){

        return name;

    }


    public  int getNumOficial(){

        return numOficial;

    }


}