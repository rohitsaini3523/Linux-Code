package model;

import java.io.Serializable;

//Java Bean

//1. Implements Serializable
//2. No arg constructor
//3. private members with getters and setters

public class Admin implements Serializable{
	public boolean check(String us,String pass) {
		if(us.compareToIgnoreCase("admin")==0 && pass.compareToIgnoreCase("12345678")==0) {
			return true;
		}
		else {
			return false;
		}
		
	}
}

