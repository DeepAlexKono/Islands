
function map()
 {
 	
	var rows = prompt("Введите количество строк");
	var columns = prompt("Введите количество столбцов");

	var matrix = new Array(rows);
	for (var i = 0; i < rows; i++) 
	{
		matrix[i] = new Array(columns);
		for(var j = 0; j < columns; j++)
		{
			matrix[i][j] = parseInt(Math.random()*10%2);
		}
	}

	alert("Вы задали карту размером " + rows + " на " + columns);

	var output = "";
	for(var i = 0; i < rows; i++)
	{
		output = output + matrix[i] + "\n";
	}
	alert(output);
 }