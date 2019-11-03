-- Find the total number of parts supplied by each supplier
SELECT sname, count(*) 
FROM suppliers, catalog 
WHERE suppliers.sid = catalog.sid 
GROUP BY sname;

-- Find the total number of parts supplied by each supplier who supplies at least 3 parts
SELECT sname, count(*) 
FROM suppliers, catalog 
WHERE suppliers.sid = catalog.sid 
GROUP BY sname 
HAVING count(*) >= 3;

-- For every supplier that supplies only green parts, print the name of the supplier and the total number of parts that he supplies
SELECT sname, count(*) 
FROM suppliers NATURAL JOIN catalog NATURAL JOIN parts 
WHERE suppliers.sid NOT IN (SELECT catalog.sid 
							FROM catalog NATURAL JOIN parts 
							WHERE parts.color <> 'Green') 
GROUP BY sname;

-- For every supplier that supplies green part and red part, print the name and the price of the most expensive part that he supplies
SELECT sname, MAX(cost)
FROM suppliers, catalog, parts 
WHERE suppliers.sid IN (SELECT S2.sid 
						FROM suppliers S2, catalog C2, parts P2
						WHERE color = 'Green' INTERSECT SELECT S3.sid FROM suppliers S3, catalog C3, parts P3 WHERE color = 'Red') 
GROUP BY sname;

-- Find the name of parts with cost lower than $_____
SELECT pname 
FROM catalog NATURAL JOIN parts 
WHERE cost < 10;

-- Find the address of the suppliers who supply _____________ (pname)
SELECT address 
FROM catalog NATURAL JOIN parts NATURAL JOIN suppliers 
WHERE pname = 'Left Handed Bacon Stretcher Cover';
