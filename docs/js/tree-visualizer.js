class TreeVisualizer {
    constructor(containerId) {
        this.container = document.getElementById(containerId);
    }

    visualizeTree(treeData) {
        // Clear previous content
        this.container.innerHTML = '';
        
        const nodeRadius = 30;
        const levelWidth = 100;
        const nodeSpacing = 100;
        const depth = treeData.length;
        const maxNodes = depth;

        // Calculate the actual tree's width and height
        const treeWidth = (depth - 1) * levelWidth;
        const treeHeight = (maxNodes - 1) * nodeSpacing;
        // Add padding
        const svgWidth = treeWidth + 2 * nodeRadius + 40;
        const svgHeight = treeHeight + 2 * nodeRadius + 40;

        // Calculate offsets to center the tree within the SVG
        const offsetX = (svgWidth - treeWidth) / 2;
        const offsetY = (svgHeight - treeHeight) / 2;

        // Create SVG element
        const svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
        svg.setAttribute("width", svgWidth);
        svg.setAttribute("height", svgHeight);
        svg.style.display = "block";
        svg.style.margin = "0 auto";
        svg.style.overflow = "visible";

        // Store node positions for drawing lines
        const positions = [];

        // Draw nodes (levels are X, nodes within level are Y)
        treeData.forEach((level, levelIndex) => {
            const x = offsetX + levelIndex * levelWidth;
            const levelHeight = (level.length - 1) * nodeSpacing;
            const startY = offsetY + (treeHeight - levelHeight) / 2;
            positions[levelIndex] = [];
            level.forEach((value, nodeIndex) => {
                const y = startY + nodeIndex * nodeSpacing;
                positions[levelIndex][nodeIndex] = { x, y };
            });
        });

        // Draw lines (connections)
        for (let i = 1; i < depth; i++) {
            for (let j = 0; j < treeData[i].length; j++) {
                if (j > 0) {
                    const line = document.createElementNS("http://www.w3.org/2000/svg", "line");
                    line.setAttribute("x1", positions[i][j].x);
                    line.setAttribute("y1", positions[i][j].y);
                    line.setAttribute("x2", positions[i-1][j-1].x);
                    line.setAttribute("y2", positions[i-1][j-1].y);
                    line.setAttribute("stroke", "#666");
                    line.setAttribute("stroke-width", "2");
                    svg.appendChild(line);
                }
                if (j < positions[i-1].length) {
                    const line = document.createElementNS("http://www.w3.org/2000/svg", "line");
                    line.setAttribute("x1", positions[i][j].x);
                    line.setAttribute("y1", positions[i][j].y);
                    line.setAttribute("x2", positions[i-1][j].x);
                    line.setAttribute("y2", positions[i-1][j].y);
                    line.setAttribute("stroke", "#666");
                    line.setAttribute("stroke-width", "2");
                    svg.appendChild(line);
                }
            }
        }

        // Draw nodes and text
        treeData.forEach((level, levelIndex) => {
            level.forEach((value, nodeIndex) => {
                const { x, y } = positions[levelIndex][nodeIndex];
                // Draw node
                const circle = document.createElementNS("http://www.w3.org/2000/svg", "circle");
                circle.setAttribute("cx", x);
                circle.setAttribute("cy", y);
                circle.setAttribute("r", nodeRadius);
                circle.setAttribute("fill", "#4CAF50");
                circle.setAttribute("stroke", "#388E3C");
                circle.setAttribute("stroke-width", "2");
                svg.appendChild(circle);
                // Add value text
                const text = document.createElementNS("http://www.w3.org/2000/svg", "text");
                text.setAttribute("x", x);
                text.setAttribute("y", y);
                text.setAttribute("text-anchor", "middle");
                text.setAttribute("dominant-baseline", "middle");
                text.setAttribute("fill", "white");
                text.setAttribute("font-size", "14px");
                text.textContent = value.toFixed(2);
                svg.appendChild(text);
            });
        });

        this.container.appendChild(svg);
    }
} 