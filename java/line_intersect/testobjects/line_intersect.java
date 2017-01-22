package org.iguanatool.casestudies.line_intersect.testobjects; 

import org.iguanatool.testobject.CaseStudy;
import org.iguanatool.testobject.InputSpecification;
import org.iguanatool.testobject.JNILibrary;
import org.iguanatool.testobject.TestObject;

public class line_intersect extends TestObject { 

	private static final CaseStudy CASE_STUDY    = new CaseStudy("line_intersect");
	private static final String TEST_OBJECT_NAME = "line_intersect";
	private static final int TEST_OBJECT_ID      = 0;
	
	static {
		System.load(new JNILibrary(CASE_STUDY, TEST_OBJECT_NAME).getLibraryFile().getPath());
	}

	protected void loadCFG() {
		loadCFG(CASE_STUDY.getCFGFile(TEST_OBJECT_NAME));
	}
	
	protected InputSpecification instantiateInputSpecification() {
		return new org.iguanatool.casestudies.line_intersect.inputspecifications.line_intersect();
	}
	
	public int getTestObjectID() {
		return TEST_OBJECT_ID;
	}
	
    protected native void call(double[] args);	
}
