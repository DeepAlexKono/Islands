(function (root) {


    var SHRI_ISLANDS = {}; // объявление объекта SHRI_ISLANDS

    SHRI_ISLANDS.WATER = 0; // инициализация полей объекта
    SHRI_ISLANDS.ISLAND = 1;

    function mapping (){
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
    return matrix;
 }
    SHRI_ISLANDS.MAP = mapping(); 

    root.SHRI_ISLANDS = SHRI_ISLANDS;
})(this);