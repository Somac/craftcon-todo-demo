type todo = {
  id: int,
  text: string,
  completed: bool
}

type state = {
  todos: list(todo)
};

type action =
  | Add(string)
  | Toggle(int)
  | Remove(int);

let str = React.string;

let initial =
  [
    {
      id: 0,
      text: "learn react-hooks",
      completed: false
    },
    {
      id: 1,
      text: "learn reasonML",
      completed: false
    }
  ];

let lastId = ref(1);
let reducer = (state, action) => 
  switch (action) {
  | Add(text) => 
    lastId := lastId^ + 1;
    {todos: [{id: lastId^, text, completed: false}, ...state.todos]}
  | Toggle(id) => 
    let todos = List.map(
      (todo) =>
        todo.id === id
          ? {...todo, completed: !todo.completed}
          : todo,
      state.todos
    );
    {todos: todos}
  | Remove(id) => 
    let todos = List.filter(
      (todo) =>
        todo.id === id
          ? false
          : true,
      state.todos
    );
    {todos: todos}
  };

[@react.component]
let make = () => {
  let ({todos}, dispatch) = React.useReducer(reducer, { todos: initial });

  <div className="todo-app">
    <h1>{str("To do app")}</h1>
    <AddTodo addTodo=((text) => dispatch(Add(text))) />
    <Todos>
      (React.array(Array.of_list(
        List.map((todo) => 
        <TodoItem
            key=(string_of_int(todo.id)) 
            item={todo.text}
            completed={todo.completed}
            toggleTodo=(() => dispatch(Toggle(todo.id)))
            removeTodo=(() => dispatch(Remove(todo.id)))
          />, todos
        )
      )))
      <Count count={List.length(todos)} />
    </Todos> 
  </div>;
};
