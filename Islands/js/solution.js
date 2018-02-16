(function (root) {
    var WATER = root.SHRI_ISLANDS.WATER;
    var ISLAND = root.SHRI_ISLANDS.ISLAND;

    /**
     * Функция находит кол-во островов на карте
     * ВАЖНО! Сигнатуру функции изменять нельзя!
     *
     * @param {number[][]} map карта островов представленная двумерной матрицей чисел
     * @returns {number} кол-во островов
     */
    function solution(map) {
        // todo: подсчитать кол-во островов на карте
        var rows =  map[0];
        var islands = 0;
        for ( var i = 0; i < map.length; i++)
        {
            for (var j = 0; j < rows.length; j++)
            {   
                if (map[i][j] == 1)
                {
                Check(map, i, j, map.length, rows.length);
                islands = islands + 1;
                }
            }
        }
        return islands;
    }
    function Check(map, i, j, M, N)
    {
        var x = i,
            y = j;
        if (y + 1 < N && map[x][y + 1] == 1) // поиск справа
        {
            // map[x][y + 1] = 0;
            // y += 1;
            deleteRight(map, x, y, M, N);
            // Check(map, x, y, M, N);
        }
        if (x + 1 < M && map[x + 1][y] == 1) // поиск внизу
        {
           // map[x + 1][y] = 0;
           // x += 1;
            deleteDown(map, x, y, M, N);
            Check(map, x, y, M, N);
        }
        if (y - 1 >= 0 && map[x][y - 1] == 1) // поиск слева
        {
           // map[x][y - 1] = 0;
           // y -= 1;
            deleteLeft(map, x, y, M, N);
            Check(map, x, y, M, N);
        }
        if (x - 1 >= 0 && map[x - 1][y] == 1) // поиск вверху
        {
           // map[x - 1][y] = 0;
           // x -= 1;
            deleteUp(map, x, y, M, N);
            Check(map, x, y, M, N);
        }
    }
    function deleteRight(map, x, y, M, N)
    {
        var a = x,
            b = y;
        map[a][b + 1] = 0;
        b += 1;
        Check(map, a, b, M, N);
    }
     function deleteLeft(map, x, y, M, N)
    {
        var a = x,
            b = y;
        map[a][b - 1] = 0;
        b -= 1;
        Check(map, a, b, M, N);
    }
     function deleteDown(map, x, y, M, N)
    {
        var a = x,
            b = y;
        map[a + 1][b] = 0;
        a += 1;
        Check(map, a, b, M, N);        
    }
     function deleteUp(map, x, y, M, N)
    {
        var a = x,
            b = y;
        map[a - 1][b] = 0;
        a -= 1;
        Check(map, a, b, M, N);        
    }
    root.SHRI_ISLANDS.solution = solution;
})(this);