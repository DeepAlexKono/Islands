(function (root) {
    var map = root.SHRI_ISLANDS.MAP;

    document.querySelector('.outer').appendChild(
        root.SHRI_ISLANDS.render(map)
    );

    var count = root.SHRI_ISLANDS.solution(map);

    document.querySelector('.outer').appendChild(
        root.SHRI_ISLANDS.render_count(count)
    );
}
)(this);