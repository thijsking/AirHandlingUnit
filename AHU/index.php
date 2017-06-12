<!DOCTYPE HTML>  
<html>
<head>
<style>
div.container {
	width: 100%;
}
header, footer {
	padding: 1em;
	color: black;
	background-color: white;
	clear: left;
	text-align: center;
	border-bottom: 5px solid grey;
}
nav {
	float: left;
	max-width: 200px;
	margin: 0;
	padding: 0;
	list-style-type: none;
}
ul {
 list-style: none;
}
nav li:hover {
    background: #EEEEEE;
}
nav li>ul {
    display: block;
    margin: 0;
    padding: 0,25;
}
nav .collapsable li>ul {
    display: none;
	list-style-type: none;
}
nav .non_collapsable li>ul {
	display: block;
}
nav li:hover>ul {
    display: block;
}
nav li>ul>li {
    display: block;
}
article {
	margin-left:210px;
	border-left: 1px solid grey;
	padding: 1em;
	overflow: hidden;
}

</style>
</head>
<body>  

<div class="container">

<header>
	<h1> A.H.U.</h1>
	<p> Air Handling unit </p>
</header>

<nav>
<ul class="collapsable">
    <a href="mode.php" target="theFrame"><li>Operation Mode </a>
	<li>Components
	<ul class="non_collapsable">
		<li>Fans
		<ul>
			<a href="fan1.php" target="theFrame"><li>Fan1 </a>
			<a href="fan2.php" target="theFrame"><li>Fan2 </a>
		</ul>
        <li>Heating Elements
		<ul>
			<a href="heating1.php" target="theFrame"><li>Heating 1 </a>
			<a href="heating2.php" target="theFrame"><li>Heating 2 </a>
		</ul>
		<li>Cooling Elements
		<ul>
			<a href="cooling.php" target="theFrame"><li>Cooling 1 </a>
		</ul>
	</ul>
	<a href="status.php" target="theFrame"><li>Status All Sensors</a>
</ul>
</nav>

<article>
<iframe frameborder="0" width="100%" height="700px" name="theFrame"></frame>
</article>

</body>
</html>