DROP TABLE IF EXISTS Professors;
DROP TABLE IF EXISTS Projects;
DROP TABLE IF EXISTS Graduate;
DROP TABLE IF EXISTS Dept;
DROP TABLE IF EXISTS Work_dept;
DROP TABLE IF EXISTS Work_project;

CREATE TABLE Professors (ssn CHAR(11) NOT NULL,
						 p_name CHAR(30) NOT NULL,
						 age INTEGER,
						 p_rank CHAR(30),
						 specialty CHAR(30),
						 PRIMARY KEY (ssn));
					
CREATE TABLE Projects (pno INTEGER NOT NULL,
					   sponsor CHAR(30),
					   m_ssn CHAR(11) UNIQUE NOT NULL,
					   w_ssn CHAR(11) NOT NULL,
					   start_date DATE NOT NULL DEFAULT CURRENT_DATE,
					   end_date DATE NOT NULL DEFAULT CURRENT_DATE,
					   budget INTEGER,
					   PRIMARY KEY (pno),
					   FOREIGN KEY (m_ssn) REFERENCES Professors(ssn),
					   FOREIGN KEY (w_ssn) REFERENCES Professors(ssn));
					 
CREATE TABLE Dept (dno INTEGER NOT NULL,
				   d_name CHAR(30),
				   office CHAR(30),
				   r_ssn CHAR(11) UNIQUE NOT NULL,
				   PRIMARY KEY (dno),
				   FOREIGN KEY (r_ssn) REFERENCES Professors(ssn));
				   
CREATE TABLE Work_dept (time_pc INTEGER,
						wd_ssn CHAR(11) NOT NULL,
						wd_dno INTEGER,
						PRIMARY KEY (wd_ssn, wd_dno),
						FOREIGN KEY (wd_ssn) REFERENCES Professors(ssn),
						FOREIGN KEY (wd_dno) REFERENCES Dept(dno));
						
CREATE TABLE Graduate (g_ssn CHAR(11) NOT NULL,
					   a_ssn CHAR(11) UNIQUE NOT NULL,
					   g_name CHAR(30) NOT NULL,
					   g_age INTEGER,
					   m_dno INTEGER UNIQUE NOT NULL,
					   deg_pg CHAR(30),
					   PRIMARY KEY (g_ssn),
					   FOREIGN KEY (m_dno) REFERENCES Dept(dno)
					   FOREIGN KEY (a_ssn) REFERENCES Graduate(g_ssn));
					   
CREATE TABLE Work_project (since DATE NOT NULL DEFAULT CURRENT_DATE,
						   wp_pno INTEGER,
						   wp_ssn CHAR(11),
						   wp_p_ssn CHAR(11) UNIQUE NOT NULL,
						   PRIMARY KEY(wp_pno, wp_ssn),
						   FOREIGN KEY (wp_pno) REFERENCES Projects (pno),
						   FOREIGN KEY (wp_ssn) REFERENCES Graduate (g_ssn),
						   FOREIGN KEY (wp_p_ssn) REFERENCES Professors (p_ssn));
					   
