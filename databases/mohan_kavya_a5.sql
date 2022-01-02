-- Kavya Mohan CS 457 Assignment #5 --
-- /Users/kavyamohan/Desktop/cs 457/mohan_kavya_a5.sql --

-- 1. Return the model number and price of all products (of any type) made by manufacturer “B”. --
(SELECT model, price FROM Product NATURAL JOIN PC WHERE maker = 'b') UNION (SELECT model, price FROM Product NATURAL JOIN Laptop WHERE maker = 'b') UNION (SELECT model, price FROM Product NATURAL JOIN Printer WHERE maker = 'b');

-- 2. Return all manufacturers that sell Laptops, but not PC’s --
SELECT DISTINCT maker FROM Product WHERE type = 'laptop' AND maker NOT IN (SELECT maker FROM Product WHERE type = 'pc');

-- 3. Return all the hard-disk sizes that occur in two or more PC’s--
SELECT DISTINCT hd FROM PC p WHERE model < any (SELECT model from PC WHERE hd = p.hd) ORDER BY hd desc;

-- 4.Return all pairs of PC models that share the same speed and RAM. Pairs should only be listed once (eg: (i,j) but not also (j,i)) --
SELECT f.model, s.model FROM PC f, PC s WHERE f.speed = s.speed AND f.ram = s.ram AND s.model > f.model;

-- 5. Return all the makers of PC’s withaspeed of at least 3.0 --
SELECT DISTINCT maker FROM Product NATURAL JOIN PC WHERE speed >= 3.0;

-- 6. Return all the printer(s) with the highest price --
SELECT model, IF(color, 'true', 'false') color, type, max(price) FROM Printer;

-- 7. Return the maker of the color printer with the lowest price --
SELECT DISTINCT maker FROM Product JOIN Printer ON Product.model = Printer.model AND price = (SELECT MIN(price) FROM Printer WHERE color = true);

-- 8. Return the average speed of laptops that cost over $1000 --
SELECT AVG(speed) FROM Laptop WHERE price > 1000;

-- 9. Return the average price of PC’s and laptops made by manufacturer “D” --
SELECT AVG(price) FROM ((SELECT price FROM Product NATURAL JOIN PC WHERE maker = 'd') UNION ALL (SELECT price FROM Product NATURAL JOIN Laptop WHERE maker = 'd'))prices;

-- 10.Return the average price of PCs for each unique speed above 2.0. (For each speed value find the averages amongst those)--
SELECT speed, AVG(price) FROM PC WHERE speed > 2.0 GROUP BY speed;