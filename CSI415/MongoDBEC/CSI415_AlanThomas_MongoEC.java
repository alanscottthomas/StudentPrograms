/*
Name: Alan Thomas
Course: CSI415-01CA
Assignment: MongoDB Extra Credit
Professor: Dr. Dulaney
Date: 4/21/2017
Notes: It was slightly difficult finding the exact jar I needed for the library. After I found it, it was smooth sailing.
A few tutorials on YouTube that were a huge help. On that note, Mongo seems like an incredible DB system, however, there's not
near as many resources to help kick start a project like there are for SQL, which seems like a deterrent at this point.
*/
 

package mongoec;
//libraries to connect/use our MongoDB
//below is a reference to the jar file, it was a bit difficult to find the exact file we needed
//https://oss.sonatype.org/content/repositories/releases/org/mongodb/mongo-java-driver/3.4.2/
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.MongoClient;


public class MongoEC {
//using main as the method to iterate through the actor collection
    public static void main(String[] args) 
    {
        try{
            MongoClient mongoClient = new MongoClient("localhost",27017);       //connection details
            DB db = mongoClient.getDB("dbname");                                  //Mongo DB name
            System.out.println("Connected to DB");                              
            
            DBCollection coll = db.getCollection("actor");                      //collection name
            DBCursor cursor = coll.find();                                      //Similar to a resultset I believe.
            
            //loop to iterate through the collection
            while(cursor.hasNext())
            {
                int i=1;
                System.out.println(cursor.next());                              //print contents from our results
                i++;
            }
        }
        catch(Exception e){
            System.out.println(e);
        }
        System.out.println("these are the results...");
        movies(null);                                                           //call movie method
    }
    //-----------------------------//
    
    
    //method to print from the movie collection
    public static void movies(String[] args) 
    {
        try{
            MongoClient mongoClient = new MongoClient("localhost",27017);
            DB db = mongoClient.getDB("dbname");
            System.out.println("Connected to DB");
            
            DBCollection coll = db.getCollection("movie");
            DBCursor cursor = coll.find();
            
            //loop to iterate through the movie collection
            while(cursor.hasNext())
            {
                int i=1;
                System.out.println(cursor.next());
                i++;
            }   
        }
        catch(Exception e){
            System.out.println(e);
        }
        System.out.println("Connected to server...");
    }
    //----------------//
}
