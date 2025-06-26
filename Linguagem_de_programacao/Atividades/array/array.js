let nomes = ["Vitor", "Ozeias", "Diego", "Matheus", "Miguel", "Gustav", 
    "Eduardo", "Rafael", "Pedro", "Gabriel", "Juliana", "Ana", "Giovana",
    "João", "José", "Danilo", "Augusto", "Fernanda", "Jader", "Glauco"];

console.log("Array: ");
for (let i = 0; i < nomes.length; i++) {
    console.log(nomes[i]);
}

console.log("");
console.log("");

nomes[0] = "Vitim";
nomes[nomes.length-1] = "Glauquin";
nomes[nomes.length/2] = "Zé";

console.log("Como ficou o array após as mudanças:");
for (let i = 0; i < nomes.length; i++) {
    console.log(nomes[i]);
}