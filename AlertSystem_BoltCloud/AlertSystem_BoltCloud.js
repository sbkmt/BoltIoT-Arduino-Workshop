// plotting graph of Temperature
var tempGraph = new boltGraph();
tempGraph.setChartType("lineGraph");
tempGraph.setAxisName('Time','Temperature');
setChartTitle("Temperature and Humidity Monitoring")
tempGraph.plotChart('time_stamp','temp');

// plotting graph of Humidity
var humidGraph = new boltGraph();
humidGraph.setChartType("lineGraph");
humidGraph.setAxisName('Time','Humidity');
humidGraph.plotChart('time_stamp','humid');