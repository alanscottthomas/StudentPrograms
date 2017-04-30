
/*

Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas

Class: CSI415

Assignment: Lab3

Purpose: Simulate 3 trains operating on a track consisting of 10 stops. Updates occur every 30 seconds

Notes: None

*/
package lab3;
 
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;
import static javax.swing.UIManager.getString;
 
/**
*
* @author Alan
*/
public class Lab3 {
 
	/**
 	* @param args the command line arguments
 	*/
	public static void main(String[] args) throws InterruptedException, ClassNotFoundException, SQLException {
   	stop_1("A");
   	TimeUnit.SECONDS.sleep(15);                   	//staggering train launch
   	stop_1("B");
   	TimeUnit.SECONDS.sleep(15);                   	//staggering train launch
   	stop_1("C");
	}
   
    
    
	//stop 1 logic
	public static void stop_1(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="1";
  	//String destination="2";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=90;                                  	//initial starting time
    	Integer counter=3;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="1";
            	String destination="2";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
            	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_2(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 
 
//stop 2 logic//
public static void stop_2(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//initial stop at the station
  	//String name = train;
  	//String departure ="2";
  	//String destination="3";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=60;                                  	//initial starting time
    	Integer counter=2;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="2";
            	String destination="3";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
               	 
                	stop_3(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);
   
	}
 //stop 3 logic
	public static void stop_3(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="3";
  	//String destination="4";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=120;                                  	//initial starting time
    	Integer counter=4;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="3";
            	String destination="4";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
               	 
                	stop_4(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 4 logic
	public static void stop_4(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="4";
  	//String destination="5";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=150;                                  	//initial starting time
    	Integer counter=5;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="4";
            	String destination="5";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_5(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 5 logic
	public static void stop_5(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="5";
  	//String destination="6";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=30;                                  	//initial starting time
    	Integer counter=1;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="5";
            	String destination="6";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_6(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 6 logic
	public static void stop_6(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="6";
  	//String destination="7";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=90;                                  	//initial starting time
    	Integer counter=3;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="6";
            	String destination="7";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
               	 
                	stop_7(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 7 logic
	public static void stop_7(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="7";
  	//String destination="8";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=90;                                  	//initial starting time
    	Integer counter=3;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="7";
            	String destination="8";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_8(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 8 logic
	public static void stop_8(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="8";
  	//String destination="9";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=60;                                  	//initial starting time
    	Integer counter=2;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="8";
            	String destination="9";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_9(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 9 logic
	public static void stop_9(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="9";
  	//String destination="10";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=180;                                  	//initial starting time
    	Integer counter=6;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="9";
            	String destination="10";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_10(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
 //stop 10 logic
	public static void stop_10(String train) throws InterruptedException, SQLException, ClassNotFoundException
	{
  	TimeUnit.SECONDS.sleep(30);                   	//insitial stop at the station, should be 30
  	//String name = train;
  	//String departure ="10";
  	//String destination="1";
  	//String location="1:30";
	 
 	 
  Timer t = new Timer();
	t.scheduleAtFixedRate(new TimerTask() {
    	//@Override
    	Integer location=90;                                  	//initial starting time
    	Integer counter=3;
 
     	public void run(){
      	 
         	try {
            	System.out.print("updated");
            	String name = train;
            	String departure ="10";
            	String destination="1";
          	 
            	String sql = "UPDATE trains_tbl SET departure=?,destination =?,location=? where name=?";
            	String myDriver = "org.gjt.mm.mysql.Driver";
             	String myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
            	Connection conn = DriverManager.getConnection(myUrl, "root", "password123");
            	PreparedStatement preparedStatement = conn.prepareStatement(sql);
            	preparedStatement.setString(1, departure);
            	preparedStatement.setString(2, destination);
            	preparedStatement.setInt(3, location);
            	preparedStatement.setString(4, name);
            	Statement st = conn.createStatement();
            	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
            	conn.close();
            	location=location-30;                                                                                  	//decrement 30 from out time
            	counter--;
            	if(counter<=0)
            	{
                	t.cancel();
               	 
                	String timeStamp = new SimpleDateFormat("HH.mm.ss").format(new Date());
               	 
                	sql = "INSERT INTO history_tbl (name,arrival,location)" + "VALUES(?,?,?)";
                	myDriver = "org.gjt.mm.mysql.Driver";
                	myUrl = "jdbc:mysql://68.188.20.101:3306/choochoo?autoReconnect=true&useSSL=false";
                	conn = DriverManager.getConnection(myUrl, "root", "password123");
                	preparedStatement = conn.prepareStatement(sql);
                	preparedStatement.setString(1, name);
                	preparedStatement.setString(2, timeStamp);
                	preparedStatement.setString(3, destination);
                	st = conn.createStatement();
                	preparedStatement.executeUpdate();                                                                     	//pushing the INSERT command to the DB   
                	conn.close();
               	 
                	stop_1(name);
            	}
        	} catch (SQLException ex) {
           	System.out.print("Error");
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (InterruptedException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	} catch (ClassNotFoundException ex) {
            	Logger.getLogger(Lab3.class.getName()).log(Level.SEVERE, null, ex);
        	}    
    	}
	}, 0, 30000);                    	//set to 5 seconds right now, this should equal how long the trip is in miliseconds
   
	}
    
    
    
}
//------------------------//



