DROP TABLE IF EXISTS keystrokes;
CREATE TABLE keystrokes(id BIGINT, vkCode INT,scanCode INT, keyState INT, timestmp BIGINT);
DROP TABLE IF EXISTS mouseactions;
CREATE TABLE mouseactions(id BIGINT, xPos INT,yPos INT,clickType INT,windowName VARCHAR(256),cursorSpot INT,timestmp BIGINT);