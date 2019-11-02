DROP TABLE IF EXISTS Customer CASCADE;--OK
DROP TABLE IF EXISTS Flight CASCADE;--OK
DROP TABLE IF EXISTS Pilot CASCADE;--OK
DROP TABLE IF EXISTS Plane CASCADE;--OK
DROP TABLE IF EXISTS Technician CASCADE;--OK

DROP TABLE IF EXISTS Reservation CASCADE;--OK
DROP TABLE IF EXISTS FlightInfo CASCADE;--OK
DROP TABLE IF EXISTS Repairs CASCADE;--OK
DROP TABLE IF EXISTS Schedule CASCADE;--OK

-------------
---DOMAINS---
-------------
CREATE DOMAIN us_postal_code AS TEXT CHECK(VALUE ~ '^\d{5}$' OR VALUE ~ '^\d{5}-\d{4}$');
CREATE DOMAIN _STATUS CHAR(1) CHECK (value IN ( 'W' , 'C', 'R' ) );
CREATE DOMAIN _GENDER CHAR(1) CHECK (value IN ( 'F' , 'M' ) );
CREATE DOMAIN _CODE CHAR(2) CHECK (value IN ( 'MJ' , 'MN', 'SV' ) ); --Major, Minimum, Service
CREATE DOMAIN _PINTEGER AS int4 CHECK(VALUE > 0);
CREATE DOMAIN _PZEROINTEGER AS int4 CHECK(VALUE >= 0);
CREATE DOMAIN _YEAR_1970 AS int4 CHECK(VALUE >= 0);
CREATE DOMAIN _SEATS AS int4 CHECK(VALUE > 0 AND VALUE < 500);--Plane Seats

------------
---TABLES---
------------
CREATE TABLE Customer
(
	id INTEGER NOT NULL,
	fname CHAR(24) NOT NULL,
	lname CHAR(24) NOT NULL,
	gtype _GENDER NOT NULL,
	dob DATE NOT NULL,
	address CHAR(256),
	phone CHAR(10),
	zipcode char(10),
	PRIMARY KEY (id)
);

CREATE TABLE Pilot
(
	id INTEGER NOT NULL,
	fullname CHAR(128),
	nationality CHAR(24),
	PRIMARY KEY (id)
);

CREATE TABLE Flight
(
	fnum INTEGER NOT NULL,
	cost _PINTEGER NOT NULL,
	num_sold _PZEROINTEGER NOT NULL,
	num_stops _PZEROINTEGER NOT NULL,
	actual_departure_date DATE NOT NULL,
	actual_arrival_date DATE NOT NULL,
	arrival_airport CHAR(5) NOT NULL,-- AIRPORT CODE --
	departure_airport CHAR(5) NOT NULL,-- AIRPORT CODE --
	PRIMARY KEY (fnum)
);

CREATE TABLE Plane
(
	id INTEGER NOT NULL,
	make CHAR(32) NOT NULL,
	model CHAR(64) NOT NULL,
	age _YEAR_1970 NOT NULL,
	seats _SEATS NOT NULL,
	PRIMARY KEY (id)
	
	--CREATE SEQUENCE user_id_seq;
	--CREATE TABLE user (
    --user_id smallint NOT NULL DEFAULT nextval('user_id_seq')
	--);
	--ALTER SEQUENCE user_id_seq OWNED BY user.user_id;

);

CREATE TABLE Technician
(
	id INTEGER NOT NULL,
	full_name CHAR(128) NOT NULL,
	PRIMARY KEY (id)
);

---------------
---RELATIONS---
---------------

CREATE TABLE Reservation
(
	rnum INTEGER NOT NULL,
	cid INTEGER NOT NULL,
	fid INTEGER NOT NULL,
	status _STATUS,
	PRIMARY KEY (rnum),
	FOREIGN KEY (cid) REFERENCES Customer(id),
	FOREIGN KEY (fid) REFERENCES Flight(fnum)
);

CREATE TABLE FlightInfo
(
	fiid INTEGER NOT NULL,
	flight_id INTEGER NOT NULL,
	pilot_id INTEGER NOT NULL,
	plane_id INTEGER NOT NULL,
	PRIMARY KEY (fiid),
	FOREIGN KEY (flight_id) REFERENCES Flight(fnum),
	FOREIGN KEY (pilot_id) REFERENCES Pilot(id),
	FOREIGN KEY (plane_id) REFERENCES Plane(id)
);

CREATE TABLE Repairs
(
	rid INTEGER NOT NULL,
	repair_date DATE NOT NULL,
	repair_code _CODE,
	pilot_id INTEGER NOT NULL,
	plane_id INTEGER NOT NULL,
	technician_id INTEGER NOT NULL,
	PRIMARY KEY (rid),
	FOREIGN KEY (pilot_id) REFERENCES Pilot(id),
	FOREIGN KEY (plane_id) REFERENCES Plane(id),
	FOREIGN KEY (technician_id) REFERENCES Technician(id)
);

CREATE TABLE Schedule
(
	id INTEGER NOT NULL,
	flightNum INTEGER NOT NULL,
	departure_time DATE NOT NULL,
	arrival_time DATE NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (flightNum) REFERENCES Flight(fnum)
);

----------------------------
-- INSERT DATA STATEMENTS --
----------------------------

COPY Customer (
	id,
	fname,
	lname,
	gtype,
	dob,
	address,
	phone,
	zipcode
)
FROM 'customer.csv'
WITH DELIMITER ',';

COPY Pilot (
	id,
	fullname,
	nationality
)
FROM 'pilots.csv'
WITH DELIMITER ',';

COPY Plane (
	id,
	make,
	model,
	age,
	seats
)
FROM 'planes.csv'
WITH DELIMITER ',';

COPY Technician (
	id,
	full_name
)
FROM 'technician.csv'
WITH DELIMITER ',';

COPY Flight (
	fnum,
	cost,
	num_sold,
	num_stops,
	actual_departure_date,
	actual_arrival_date,
	arrival_airport,
	departure_airport
)
FROM 'flights.csv'
WITH DELIMITER ',';

COPY Reservation (
	rnum,
	cid,
	fid,
	status
)
FROM 'reservation.csv'
WITH DELIMITER ',';

COPY FlightInfo (
	fiid,
	flight_id,
	pilot_id,
	plane_id
)
FROM 'flightinfo.csv'
WITH DELIMITER ',';

COPY Repairs (
	rid,
	repair_date,
	repair_code,
	pilot_id,
	plane_id,
	technician_id
)
FROM 'repairs.csv'
WITH DELIMITER ',';

COPY Schedule (
	id,
	flightNum,
	departure_time,
	arrival_time
)
FROM 'schedule.csv'
WITH DELIMITER ',';


--Trigger for adding plane
DROP SEQUENCE IF EXISTS plane_add_seq CASCADE;
CREATE SEQUENCE plane_add_seq START WITH 67;

DROP FUNCTION IF EXISTS add_plane_func() CASCADE;
CREATE OR REPLACE FUNCTION add_plane_func()
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.id := nextval('plane_add_seq');
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER add_plane_trigger BEFORE INSERT ON plane
	FOR EACH ROW EXECUTE PROCEDURE add_plane_func();
	
--Trigger for adding Flight
DROP SEQUENCE IF EXISTS flight_add_seq CASCADE;
CREATE SEQUENCE flight_add_seq START WITH 2000;

DROP FUNCTION IF EXISTS add_flight_func() CASCADE;
CREATE OR REPLACE FUNCTION add_flight_func()
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.fnum := nextval('flight_add_seq');
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER add_flight_trigger BEFORE INSERT ON flight
	FOR EACH ROW EXECUTE PROCEDURE add_flight_func();


--Trigger for adding Flightinfo
DROP SEQUENCE IF EXISTS flightinfo_add_seq CASCADE;
DROP SEQUENCE IF EXISTS flightinfo2_add_seq CASCADE;

CREATE SEQUENCE flightinfo_add_seq START WITH 2000;
CREATE SEQUENCE flightinfo2_add_seq START WITH 2000;


DROP FUNCTION IF EXISTS add_flightinfo_func() CASCADE;
CREATE OR REPLACE FUNCTION add_flightinfo_func()
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.fiid := nextval('flightinfo_add_seq');
		new.flight_id := nextval('flightinfo2_add_seq');
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER add_flightinfo_trigger BEFORE INSERT ON flightinfo
	FOR EACH ROW EXECUTE PROCEDURE add_flightinfo_func();

--Trigger for adding Pilot
DROP SEQUENCE IF EXISTS pilot_add_seq CASCADE;
CREATE SEQUENCE pilot_add_seq START WITH 250;

DROP FUNCTION IF EXISTS add_pilot_func() CASCADE;
CREATE OR REPLACE FUNCTION add_pilot_func()
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.id := nextval('pilot_add_seq');
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER add_pilot_trigger BEFORE INSERT ON pilot
	FOR EACH ROW EXECUTE PROCEDURE add_pilot_func();
	

--Trigger for adding Technician
DROP SEQUENCE IF EXISTS tech_add_seq CASCADE;
CREATE SEQUENCE tech_add_seq START WITH 250;

DROP FUNCTION IF EXISTS add_tech_func() CASCADE;
CREATE OR REPLACE FUNCTION add_tech_func()
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.id := nextval('tech_add_seq');
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER add_tech_trigger BEFORE INSERT ON technician
	FOR EACH ROW EXECUTE PROCEDURE add_tech_func();
	
--Trigger for adding Reservation
DROP SEQUENCE IF EXISTS res_add_seq CASCADE;
CREATE SEQUENCE res_add_seq START WITH 9999;

DROP FUNCTION IF EXISTS add_res_func() CASCADE;
CREATE OR REPLACE FUNCTION add_res_func()
	RETURNS trigger AS
$BODYS$
	BEGIN
		new.rnum := nextval('res_add_seq');
		RETURN new;
	END;
$BODYS$
LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER add_res_trigger BEFORE INSERT ON reservation
	FOR EACH ROW EXECUTE PROCEDURE add_res_func();
	
	
