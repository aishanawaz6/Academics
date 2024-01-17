#You will have to create a star topolgy as given in the diagram below using ns2 to implement the Distance vector routing protocol. Assume all the devices in the #following star topology as nodes and all the wires as duplex links having a capacity of 512Kb and a propagation delay of 10ms with a stochastic fair queue #scheduling algorithm.
#You will have to send TCP data from H1 to H4 having red color. Also you will have to send UDP data with a rate of 256Kbps from H2 to H5 having blue color.
#Scheduling Events:
#	TCP Data starts at 0.1 and stops at 1.5
#	UDP Data starts at 0.2 and stops at 1.3
#	Bring the link between SW1 and H5 down at 0.5 and bring it back up at 0.9
#	Bring the link between SW1 and H4 down at 0.7 and bring it back up at 1.2
#	Stop the simulation at 2.0

#Creating simulator object 
set ns [new Simulator]  
 
#creating Two color classes for ns object to distinguish the traffic coming from various sources
$ns color 0 blue
$ns color 1 red

#Creating the nam file
set nf [open out.nam w]    
  
#It opens the file 'out.nam' for writing and gives it the file handle 'nf'. 
$ns namtrace-all $nf

#Finish Procedure  (closes the trace file and starts nam)
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
        }


#Defining Nodes
for {set j 0} {$j<7} {incr j} {
set arr($j) [$ns node]
}

for {set j 0} {$j<6} {incr j} {
$ns duplex-link $arr(0) $arr([expr ($j+1)%7]) 512Kb 10ms SFQ    
}
$ns duplex-link-op $arr(0) $arr(1) orient right-up
$ns duplex-link-op $arr(0) $arr(2) orient right
$ns duplex-link-op $arr(0) $arr(3) orient right-down
$ns duplex-link-op $arr(0) $arr(4) orient left-down
$ns duplex-link-op $arr(0) $arr(5) orient left
$ns duplex-link-op $arr(0) $arr(6) orient left-up

$ns rtproto DV

#Creating a TCP agent and connecting it to node 1 (Basically it defines source node of TCP)
set tcp0 [new Agent/TCP]
$ns attach-agent $arr(2) $tcp0        

#Creating a Sink Agent and attaching it to node 4
set sink0 [new Agent/TCPSink]
$ns attach-agent $arr(5) $sink0

#Connecting TCP agent with Sink agent
$ns connect $tcp0 $sink0

#Creating FTP agent for traffic and attching it to tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

$tcp0 set fid_ 1
#Specifying the UDP agent
set udp0 [new Agent/UDP]
$udp0 set fid_ 0
#Attaching the UDP agent with node 2
$ns attach-agent $arr(3) $udp0

#Specifying the Null agent
set null0 [new Agent/Null]

#Attaching the NULL agent with node 5
$ns attach-agent $arr(6) $null0

#Connecting both udp0 and null0 agents for transferring data between node 2 and node 5
$ns connect $udp0 $null0
 
#Specifying the CBR agent to generate the traffic over udp0 agent
set cbr0 [new Application/Traffic/CBR]

#Each packet having 500 bytes
$cbr0 set packetSize_ 256000

#EAch packet will be generated after 5ms i.e., 200 packets per second
$cbr0 set interval 0.005 

#Attaching cbr0 with udp0
$cbr0 attach-agent $udp0

#Starting the cbr0 at 0.2 simulaio time
$ns at 0.2 "$cbr0 start"
#Stoping the cbr0 at 1.3 simulation time
$ns at 1.3 "$cbr0 stop"

#Starting the FTP Traffic
$ns at 0.1 "$ftp0 start"
$ns at 1.5 "$ftp0 stop"

#Bring the link between SW1 and H5 down at 0.5 and bring it back up at 0.9
$ns rtmodel-at 0.5 down $arr(0) $arr(6)
$ns rtmodel-at 0.9 up  $arr(0) $arr(6)

#Bring the link between SW1 and H4 down at 0.7 and bring it back up at 1.2
$ns rtmodel-at 0.7 down $arr(0) $arr(5)
$ns rtmodel-at 1.2 up  $arr(0) $arr(5)



#Stop the simulation at 2.0
$ns at 2.0 "finish"
#Run the simulation
$ns run


