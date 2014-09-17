Counter = 0;
for n = 1:length(simout.time)
    
[y(n), Counter(n+1)] = Ideal_Alternator_Trigger(simout.Data(n,1),Counter(n));
end

figure (1)
subplot 211
plot(y)
hold on
plot(simout.Data(:,1),'r.')
legend('TorqueOut','Engine Mode')
subplot 212
plot(Counter)