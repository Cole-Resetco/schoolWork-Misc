DROP TABLE IF EXISTS Musicians;
DROP TABLE IF EXISTS Album;
DROP TABLE IF EXISTS Instrument;
DROP TABLE IF EXISTS Songs;
DROP TABLE IF EXISTS Home;
DROP TABLE IF EXISTS Place;
DROP TABLE IF EXISTS Telephone;

CREATE TABLE Musicians (m_ssn CHAR(11) NOT NULL,
						m_name CHAR(30) NOT NULL,
						inst_id CHAR(30),
						m_song_id CHAR(30),
						PRIMARY KEY (m_ssn),
						FOREIGN KEY (inst_id) REFERENCES Instrument (inst_id),
						FOREIGN KEY (m_song_id) REFERENCES Songs (song_id),
						ON DELETE NO ACTION);
						
CREATE TABLE Album (album_id CHAR(30) NOT NULL,
					copyright_date DATE NOT NULL DEFAULT CURRENT_DATE,
					speed INTEGER NOT NULL,
					p_ssn CHAR(11) UNIQUE NOT NULL,
					title CHAR(30) NOT NULL,
					PRIMARY KEY (album_id),
					FOREIGN KEY (p_ssn) REFERENCES Musicians (m_ssn),
					ON DELETE NO ACTION);
					
CREATE TABLE Instrument (inst_id CHAR(30) NOT NULL,
						 d_name CHAR(30),
						 inst_key CHAR(2) NOT NULL,
						 PRIMARY KEY (inst_id),
						 ON DELETE NO ACTION);
						 
CREATE TABLE Songs (song_id CHAR(30) NOT NULL,
					title CHAR(30),
					A_album_id CHAR(30) UNIQUE NOT NULL,
					Author CHAR(30),
					PRIMARY KEY (song_id),
					FOREIGN KEY (A_album_id) REFERENCES Album (album_id),
					ON DELETE NO ACTION);
					
CREATE TABLE Place (address CHAR(30) NOT NULL,
					PRIMARY KEY (address),
					ON DELETE NO ACTION);
					
CREATE TABLE Telephone (phone_no CHAR(30) NOT NULL,
						h_address CHAR(30) UNIQUE NOT NULL,
						PRIMARY KEY (phone_no),
						FOREIGN KEY (h_address) REFERENCES Home (p_address), 
						ON DELETE NO ACTION);
		
CREATE TABLE Home (p_address CHAR(30) NOT NULL,
				   l_ssn CHAR(11),
				   PRIMARY KEY (p_address),
				   FOREIGN KEY (p_address) REFERENCES Place (address),
				   FOREIGN KEY (l_ssn) REFERENCES Musicians (m_ssn),
				   ON DELETE NO ACTION);
