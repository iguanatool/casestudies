package org.iguanatool.casestudies.calendar.inputspecifications; 

import org.iguanatool.testobject.InputSpecification;

public class days_between extends InputSpecification {
	
	public void defaultSetup() {
		addInt(6, -32768, 32767);
	}
}
